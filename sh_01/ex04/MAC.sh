ifconfig | grep -E '((([0-9a-f]{2}):){5})([0-9a-f]{2})' | awk '{print $2}'
