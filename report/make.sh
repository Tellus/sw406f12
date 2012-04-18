#! /bin/sh

echo "Pulling fresh Git data..."

git pull

echo "\tDone."

echo "Making a new PDF snapshot..."

pdflatex -interaction=batchmode master.tex
# pdflatex -interaction=batchmode master.tex
bibtex master.aux
# pdflatex -interaction=batchmode master.tex
pdflatex -interaction=batchmode master.tex

echo "\tDone."

echo "Cleaning up..."

sh clean.sh

echo "\tDone."
