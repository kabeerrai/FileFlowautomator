#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#define WATCH_DIR "./watch_folder"

// Logging function
void log_action(const char *filename, const char *destination) {
    FILE *log = fopen("fileflow.log", "a");
    if (!log) return;

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // remove newline

    fprintf(log,
        "[%s] File: %s -> Moved to %s\n",
        time_str, filename, destination);

    fclose(log);
}


int main() {
    DIR *dir = opendir(WATCH_DIR);
    struct dirent *entry;
    struct stat fileStat;

    if (!dir) {
        perror("Failed to open watch directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {

        // Ignore non-regular files
        if (entry->d_type != DT_REG)
            continue;

        char filepath[512];
        snprintf(filepath, sizeof(filepath), "%s/%s", WATCH_DIR, entry->d_name);

        // Get file metadata
        if (stat(filepath, &fileStat) != 0)
            continue;

        // Zero-byte purge
        if (fileStat.st_size == 0) {
            remove(filepath);
            log_action("Deleted zero-byte file", entry->d_name);
            continue;
        }

        // Permission guard
        if (access(filepath, R_OK | W_OK) != 0) {
            log_action("Permission denied, skipped", entry->d_name);
            continue;
        }

        // Extension classifier
        char *ext = strrchr(entry->d_name, '.');
        char dest[256] = "./Misc";

        if (ext) {
            if (!strcmp(ext, ".txt") || !strcmp(ext, ".pdf"))
                strcpy(dest, "./Documents");
            else if (!strcmp(ext, ".jpg") || !strcmp(ext, ".png"))
                strcpy(dest, "./Images");
	    else if (!strcmp(ext,  ".cpp") || !strcmp(ext, ".c") || !strcmp(ext, ".sh"))
		strcpy(dest, "./Code");
            else if (!strcmp(ext, ".mp4"))
                strcpy(dest, "./Videos");
        }

        // Ensure destination exists
        mkdir(dest, 0777);

        char newpath[512];
        snprintf(newpath, sizeof(newpath), "%s/%s", dest, entry->d_name);

        rename(filepath, newpath);
	log_action(entry->d_name, dest);


        

    }

    closedir(dir);
    return 0;
}
