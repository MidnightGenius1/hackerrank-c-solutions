#define p 131
#define M 1000000007


double hashing( char* password)
{
	double hash_value = 0;

	psw_len = strlen(password);
	
	for(int i = 0; i < psw_len; i++)
	{
		hash_value += (int)password[i] * pow(p,psw_len-(i+1));
	}

	retrun (hash_value % M); 
}



int* authEvents(int events_rows, int events_columns, char*** events, int* result_count) 
{
	double authorize = 0;
	double hash_value = 0;
	double hash_value_2 = 0;
	int res_count = 0;
	char * password   = (char*) malloc(10 * sizeof(char));
	char * password_2 = (char*) malloc(10 * sizeof(char));
	int* result = (int*) malloc(events_rows * sizeof(int));

	for(int i =0; i < event_rows; i++)
	{
		if(events[i][0][0] == 's')
		{
			for ( int j = 0; events[i][1][j] =! '\0' ; j++)
			{
				password[j] = events[i][1][j];
				password_2[j] = events[i][1][j];
			}

			if(events[i][1][j] == '\0')
			{
				password[j] = '\0';
				password_2[j] = 'z';
				password_2[j+1] = '\0';
			}
		}

		else if(events[i][0][0] == 'a')
		{
			for ( int j = 0; events[i][1][j] =! '\0'; j++)
			{
				authorize = authorize * 10;
				authorize += (int)events[i][1][j] - 48;
			}
		}
		
		hash_value = hashing(password);
		hash_value_2 = hashing(password_2);

		if ( authorize >= hash_value && authorize <= hash_value_2)
		{
			result[res_count] = 1;
			res_count++;
		}
		else
		{
			result[res_count] = 0;
			res_count++;
		}
	}

	return result;

}