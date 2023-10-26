# C_geometry_dash


# install xorg
sudo apt-get install xorg

# per l'avvio il file eseguibile è a
gcc -o a main.c rect.c game.c floring.c matrix.c -lX11
./a

