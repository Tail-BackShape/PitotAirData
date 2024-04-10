set title "AirSpeed resolution(As res)"
set xlabel "dP"
set ylabel "As res"
set grid
set samples 2000
plot [2048:4096][0:1.3] sqrt((2.*((4000./4096.)*(x-2048.)))/1.293) - sqrt((2.*((4000./4096.)*((x-1)-2048.)))/1.293) \
    title "Res-disp" w l lw 2
pause -1

