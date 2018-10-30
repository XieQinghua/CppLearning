/*
** Author:Jason Lee
** Date:2018-10-29 
*/

#include<iostream>
#include<cmath>

using namespace std;

float input[][12] = {
	9,9,9,4.67,5.5,7.33,8.25,7.42,7.6,2,2,2,
	9,9,9,4.67,5.5,7.33,8.25,7.42,7.6,2,2,2,
	1.43,1.43,1.43,10.22,1.42,6.33,2,8,11.4,9.88,9.88,9.88,
	4,4,4,8.78,5.92,12.83,1.5,4.58,1.6,3.88,3.88,3.88,
	7.86,7.86,7.86,10.67,0.25,13.33,6.25,1.17,1,6.63,6.63,6.63,
	13.71,13.71,13.71,7.33,2.33,3.17,12,1.25,10.6,2.13,2.13,2.13,
	13.71,13.71,13.71,0.44,0.42,8.17,4.25,2.17,15.6,7.5,7.5,7.5,
	2.29,2.29,2.29,9.44,0.83,7.5,7.38,7,18.6,3.25,3.25,3.25,
	13.86,13.86,13.86,10.33,6.83,10.83,2.75,2.08,2.6,8.13,8.13,8.13,
	13.71,13.71,13.71,7.56,5.75,11.83,9.38,6.75,11.4,8.63,8.63,8.63,
	7,7,7,8.44,2.67,12.5,3.25,2,9.4,9.38,9.38,9.38,
	11.43,11.43,11.43,8.22,7.92,4.67,6.38,7.75,0.2,5.63,5.63,5.63,
	2,2,2,4.33,0.25,11.33,8.75,2.92,6.8,1,1,1
};


float variance(float*cacluate) {
	float avg = 0.0f;
	float var = 0.0f;
	// calculate the average amount 
	for (int i = 0; i < 12;i++) {
		avg += cacluate[i];
	}
	avg /= 12.0;
	// calculate the variance
	for (int i = 0; i < 12; i++) {
		var += pow((cacluate[i] - avg), 2);
	}
	var /= 12;
	return var;
}

/*
** @brief:Select the data that meets the requirements first from the input array,
** and then calculate the variance.
*/
void caluateSEofMatrix() {
	int status[12];
	float min[12];
	float cacluate[12];
	int coordinate[12];
	int min_coord[12];
	float min_var = 1000.0f;
	fill(status, status + 12, 0);
	for (int i = 0; i < 12; i++)
	{
		min[i] = input[i][i];
	}
	// select the data which meets the requirments
	for (int i1 = 0; i1 < 12; i1++)
	{
		cout << "i1 = " << i1 << endl;
		status[i1]++;
		cacluate[0] = input[1][i1];
		coordinate[0] = i1;
		// the second row.
		for (int i2 = 0; i2 < 12; i2++)
		{
			// this column have visited.
			if (status[i2])
				continue;
			status[i2]++;
			cacluate[1] = input[2][i2];
			coordinate[1] = i2;
			// the third row.
			for (int i3 = 0; i3 < 12; i3++)
			{
				// this column have visited.
				if (status[i3])
					continue;
				status[i3]++;
				cacluate[2] = input[3][i3];
				coordinate[2] = i3;
				// the fourth row.
				for (int i4 = 0; i4 < 12; i4++)
				{
					// this column have visited.
					if (status[i4])
						continue;
					status[i4]++;
					cacluate[3] = input[4][i4];
					coordinate[3] = i4;
					// the fifth row.
					for (int i5 = 0; i5 < 12; i5++)
					{
						// this column have visited.
						if (status[i5])
							continue;
						status[i5]++;
						cacluate[4] = input[5][i5];
						coordinate[4] = i5;
						// the sixth row.
						for (int i6 = 0; i6 < 12; i6++)
						{
							// this column have visited.
							if (status[i6])
								continue;
							status[i6]++;
							cacluate[5] = input[6][i6];
							coordinate[5] = i6;
							// the seventh row.
							for (int i7 = 0; i7 < 12; i7++)
							{
								// this column have visited.
								if (status[i7])
									continue;
								status[i7]++;
								cacluate[6] = input[7][i7];
								coordinate[6] = i7;
								// the eighth row
								for (int i8 = 0; i8 < 12; i8++)
								{
									// this column have visited.
									if (status[i8])
										continue;
									status[i8]++;
									cacluate[7] = input[8][i8];
									coordinate[7] = i8;
									// the nineth row
									for (int i9 = 0; i9 < 12; i9++)
									{
										// this column have visited.
										if (status[i9])
											continue;
										status[i9]++;
										cacluate[8] = input[9][i9];
										coordinate[8] = i9;
										// the tenth row.
										for (int i10 = 0; i10 < 12; i10++)
										{
											// this column have visited.
											if (status[i10])
												continue;
											status[i10]++;
											cacluate[9] = input[10][i10];
											coordinate[9] = i10;
											// the eleventh row.
											for (int i11 = 0; i11 < 12; i11++)
											{
												// this column have visited.
												if (status[i11])
													continue;
												status[i11]++;
												cacluate[10] = input[11][i11];
												coordinate[10] = i11;
												// the twelfth row.
												for (int i12 = 0; i12 < 12; i12++)
												{
													// this column have visited.
													if (status[i12])
														continue;
													cacluate[11] = input[12][i12];
													coordinate[11] = i12;
													float temp = variance(cacluate);
													if (temp < min_var) {
														for (int i = 0; i < 12; i++)
														{
															min[i] = cacluate[i];
															min_coord[i] = coordinate[i];
														}
														min_var = temp;
													}
												}// the twelfth row
												status[i11]--;
											}// the eleventh row.
											status[i10]--;
										}// the tenth row.
										status[i9]--;
									}// the nineth row
									status[i8]--;
								}// the eighth row
								status[i7]--;
							}// the seventh row.
							status[i6]--;
						}// the sixth row.
						status[i5]--;
					}// the fifth row.
					status[i4]--;
				}// the fourth row.
				status[i3]--;
			}// the second row.
			status[i2]--;
		}// the second row.	
		status[i1]--;
	}
	cout << "min_var:" << min_var << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << "coordinate:" << "(" << i + 1 << "," << (char)(min_coord[i] + 'A') << ")=" << min[i] << endl;
	}

}

int main(){
	caluateSEofMatrix();
	return 0;
} 
