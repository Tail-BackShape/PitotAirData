set title "MPX7002DP"
set xlabel "Differential Pa"
set ylabel "AirSpeed"
set grid
plot [0:1*10**3] sqrt((2*x)/1.293) title "v=sqrt((2*Pa)/1.293)"
pause -1
