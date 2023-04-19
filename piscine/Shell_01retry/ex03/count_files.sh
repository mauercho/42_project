find . | wc -l | awk '{ sub(/^[ \t]+/, ""); print }'
