set title "AirSpeed resolution(As res)"
set xtics 200 nomirror
set ytics 0.1 nomirror
set y2tics 5 nomirror
set xlabel "dP"
set ylabel "As res"
set y2label "As"
set grid
set samples 2000

plot [2049:4096] sqrt((2.*((4000./4096.)*(x-2048.)))/1.293) - sqrt((2.*((4000./4096.)*((x-1)-2048.)))/1.293) \
    title "Res-disp" w l lw 2 axis x1y1, \
    [2048:4096] sqrt((2.*((4000./4096.)*(x-2048.)))/1.293) \
    title "V" w l lw 2 axis x1y2

pause -1
