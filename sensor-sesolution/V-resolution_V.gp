set title "AirSpeed resolution(As res)"
set xtics 200 nomirror
set ytics 0.1 nomirror
set y2tics 5 nomirror
set xlabel "dP"
set ylabel "As res"
set y2label "As"
set grid
set samples 2000

#ADC is 12bit, 0-4095  [2049:4096]
#plot [2049:4096] sqrt((2.*((2049./4096.)*(x-2048.)))/1.293) - sqrt((2.*((2049./4096.)*((x-1)-2048.)))/1.293) \
#    title "Res-disp" w l lw 2 axis x1y1, \
#    [2049:4096] sqrt((2.*((2049./4096.)*(x-2048.)))/1.293) \
#    title "AirSpeed" w l lw 2 axis x1y2

#ADC is 15bit, 0-32767 [16384:32767]
plot [16384:32767] sqrt((2.*((16384./32767.)*(x-16383.)))/1.293) - sqrt((2.*((16383./32767.)*((x-1)-16383.)))/1.293) \
    title "Res-disp" w l lw 2 axis x1y1, \
    [16384:32767] sqrt((2.*((16384./32767.)*(x-16383.)))/1.293) \
    title "AirSpeed" w l lw 2 axis x1y2

pause -1
