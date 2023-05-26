for f in **/*.c; do
    mv -- "$f" "${f%.*}_bonus.c"
done
