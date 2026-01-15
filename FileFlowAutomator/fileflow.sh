#!/bin/bash

echo "=================================="
echo " FileFlow Automator Started"
echo " To end press 1"
echo "=================================="

while true
do
    # Run fileflow in background
    ./fileflow

    # Wait 5 seconds OR user input
    read -t 5 -n 1 key

    if [[ "$key" == "1" ]]; then
        echo ""
        echo "Stopping FileFlow Automator..."
        exit 0
    fi
done

