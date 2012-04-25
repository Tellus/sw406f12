#! /bin/sh


echo "Making a new PDF snapshot..."

pdflatex -interaction=batchmode master.tex
pdflatex -interaction=batchmode master.tex
bibtex master.aux
pdflatex -interaction=batchmode master.tex
pdflatex -interaction=batchmode master.tex

echo "\tDone."

