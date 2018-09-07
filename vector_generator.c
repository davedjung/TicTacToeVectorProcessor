#include <stdio.h>

bool end(int temp[18]);

int main(){
	FILE *fp = fopen("vector.txt", "w");
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			for (int k=0; k<3; k++){
				for (int l=0; l<3; l++){
					for (int m=0; m<3; m++){
						for (int n=0; n<3; n++){
							for (int o=0; o<3; o++){
								for (int p=0; p<3; p++){
									for (int q=0; q<3; q++){
										int temp[18];
										temp[0] = q;
										temp[1] = p;
										temp[2] = o;
										temp[3] = n;
										temp[4] = m;
										temp[5] = l;
										temp[6] = k;
										temp[7] = j;
										temp[8] = i;
										//convert to 18-dimensional vector
										for (int r=9; r<18; r++){
											temp[r] = 0;
										}
										for (int s=0; s<9; s++){
											if (temp[s]==2){
												temp[s+9] = 1;
												temp[s] = 0;
											}
										}
										//check if vector is valid
										if (!end(temp)){
											//write to file
											for (int t=0; t<18; t++){
												fprintf(fp, "%d", temp[t]);
											}
											fprintf(fp, "\n");
										}	
									}
								}
							}
						}
					}
				}
			}
		}
	}
	fclose(fp);
	return 0;
}

bool end(int temp[18]){
	//check full
	int count = 0;
	for (int h=0; h<18; h++){
		if (temp[h]==1){
			count++;
		}
	}
	if (count==9){
		return true;
	}
	//check vertical
	for (int i=0; i<3; i++){
		if (temp[i]==1 && temp[i]==temp[i+3] && temp[i+3]==temp[i+6]){
			return true;
		} else if (temp[i+9]==1 && temp[i+9]==temp[i+12] && temp[i+12]==temp[i+15]){
			return true;
		}
	}
	//check horizontal
	for (int j=0; j<7; j+=3){
		if (temp[j]==1 && temp[j]==temp[j+1] && temp[j+1]==temp[j+2]){
			return true;
		} else if (temp[j+9]==1 && temp[j+9]==temp[j+10] && temp[j+10]==temp[j+11]){
			return true;
		}
	}
	//check diagonal
	if (temp[4]==1){
		if (temp[0]==1 && temp[8]==1){
			return true;
		} else if (temp[2]==1 && temp[6]==1){
			return true;
		}
	} else if (temp[13]==1){
		if (temp[9]==1 && temp[17]==1){
			return true;
		} else if (temp[11]==1 && temp[15]==1){
			return true;
		}
	}
	return false;
}