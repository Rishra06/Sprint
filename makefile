
all: hospital_details

hospital_details: hospital_details_def.o hospital_details_main.o
	gcc hospital_details.h hospital_details_def.c hospital_details_main.c -o hospital_details

hospital_details_def.o: hospital_details_def.c
	gcc -c hospital_details.h hospital_details_def.c
           
hospital_details_main.o: hospital_details_main.c
	gcc -c hospital_details.h hospital_details_main.c
