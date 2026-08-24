// Aneri Raval (2410110402) : Assignment 1 Source Code

// QUESTION 3

#include <stdio.h>
#include <stdlib.h>
void print_file( char *label, char *path){
	FILE *fp = fopen(path, "r"); // File is opened in 'read' mode
	if (fp==NULL){
		printf("Error"); // Error message in case file doesn't exist
		return;
	}
	char a[1024]; // Temporary array for file storage
	if (fgets(a, sizeof(a),fp) !=NULL){
		printf ("%s:%s", label, a);
	}
	fclose(fp); // Close file
}
int main(){
	print_file("Operating System","/proc/sys/kernel/ostype");
	print_file("Kernel Release", "/proc/sys/kernel/osrelease"); 
	print_file("Kernel Version Info", "/proc/version");
	return 0;
}

// QUESTION 4

include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char path[256]; // Initialization of Variables
	char line[256];
	char name[256];
	char state[256];
	int ppid,pid;
	int uid;
	FILE *f;
	printf("%-8s %-20s %-8s %-8s %-8s\n", "PID", "NAME", "STATE", "PPID", "UID");
    	printf("----------------------------------------------------\n");
    	for (int i = 1; i <= 1000; i++) {
        	sprintf(path, "/proc/%d/status", i);
       	 	f = fopen(path, "r");
        	if (f == NULL) {
            		continue; // If PID doesn't exist, skip to the next number
        	}	
    	
		char label[50];
		while (fscanf(f,"%s",label) !=EOF){
			if (strcmp(label,"Name:")==0){
				fscanf(f,"%s",name); // Values are stored in the file
			}
			else if (strcmp(label,"State:")==0){
				fscanf(f,"%s",state);
			}
			else if (strcmp(label,"PPid:")==0){
				fscanf(f,"%d",&ppid);
			}
			else if (strcmp(label,"Uid:")==0){
				fscanf(f,"%d",&uid);
			}
		}
		printf("%-8d %-20s %-8s %-8d %-8d\n", i, name, state, ppid, uid); //Values are printed
		fclose(f);
	}

    return 0;
}	