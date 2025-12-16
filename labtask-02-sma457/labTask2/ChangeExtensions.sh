#!/bin/sh

# Requires exactly two arguments
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <old_ext> <new_ext>" >&2
  exit 1
fi

old_ext=${1#.}
new_ext=${2#.}

# Check if any files match *.<old_ext> in the current dir
set -- *."$old_ext"
if [ "$1" = "*.$old_ext" ]; then
  echo "No files with extension .$old_ext found in $(pwd)" >&2
  exit 2
fi

# Rename the file and print what changed
for f in *."$old_ext"; do
  base=${f%.*}                   # remove the last dot + extension
  new_name="${base}.${new_ext}"
  # Try mv with -- (GNU), fall back for BSD/macOS
  mv -- "$f" "$new_name" 2>/dev/null || mv "$f" "$new_name"
  echo "Renamed: $f -> $new_name"
done

