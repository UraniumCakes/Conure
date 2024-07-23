# Conure
MOOSE application for reading files

# Steps for reading file 
1) Activate MOOSE conda environment
2) Paste command line to read your file
# Copyable commands 
## Running a test
```
conda activate moose  
~/projects/moose/test/tests/mesh/gmsh$ ~/projects/moose/modules/combined/combined-opt -i gmsh_test.i 
```
(replace gmsh_test.i with the name of your file) <br />

## Running a problem<br />
```
cd ~/projects/moose/examples/ex01_inputfile 
make -j8 
./ex01-opt -i ex01.i 
```
## When storing changes on GitHub : 
```
cd/home/uranium_cakes/projects/conure
git remote add origin https://github.com/UraniumCakes/conure  <br />
git commit -m "Initial code commit"  <br />
git push -u origin main
```
