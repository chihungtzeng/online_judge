#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 64
#define LINE_LEN 1024
#define MAX 20001

enum {
	DEPARTMENT,
	TITLE,
	FIRST_NAME,
	LAST_NAME,
	ADDRESS,
	HOME_PHONE,
	WORK_PHONE,
	CAMPUS_BOX,
	nEntry
};

struct Record {
	char *data[nEntry];
};

struct Record *newRecord(char *department, char *dataList){
	struct Record *pRecord;
	char *tok, i;
	pRecord = (struct Record *) malloc(sizeof(struct Record));

	
	pRecord->data[DEPARTMENT] = strdup(department);
	tok = strtok(dataList, ",\n");
	i=1;
	while(i < nEntry){
		pRecord->data[i++] = strdup(tok);
		tok = strtok(NULL, ",\n");
	}
	return pRecord;
}

int compareRecord(const void *a, const void *b){
	struct Record *x, *y;
	x = *(struct Record **)a;
	y = *(struct Record **)b;
	return strcmp(x->data[LAST_NAME], y->data[LAST_NAME]);
}

void printRecord(struct Record *pRecord){
	printf("----------------------------------------\n");
	printf("%s %s %s\n", pRecord->data[TITLE], pRecord->data[FIRST_NAME], pRecord->data[LAST_NAME]);
	printf("%s\n", pRecord->data[ADDRESS]);
	printf("Department: %s\n", pRecord->data[DEPARTMENT]);
	printf("Home Phone: %s\n", pRecord->data[HOME_PHONE]);
	printf("Work Phone: %s\n", pRecord->data[WORK_PHONE]);
	printf("Campus Box: %s\n", pRecord->data[CAMPUS_BOX]); 
}

int main(){
	char department[LEN];
	char line[LINE_LEN];
	int nDepartment;
	struct Record *record[MAX];
	int nRecord, i, j;
	FILE *fp = stdin;
	fgets(line, LINE_LEN, fp);
	nDepartment = atoi(line);
	nRecord = 0;
	
	
	while(nDepartment){
		fgets(department, LEN, fp);
		i = strlen(department);
		department[i-1] = '\0';
		while(NULL != fgets(line, LINE_LEN, fp)){
			if(line[0] == '\n') {
				break;
			}
			else {
				record[nRecord++] = newRecord(department, line);
			}
		}
		nDepartment--;
	}
	qsort(record, nRecord, sizeof(struct Record *), compareRecord);
	for(i=0; i<nRecord; i++){
		printRecord(record[i]);
	}
	for(i=0; i<nRecord; i++){

		for(j=0; j<nEntry; j++){

				free(record[i]->data[j]);

		}
		free(record[i]);
	}
	
	return 0;
}
