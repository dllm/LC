int strStr(char* haystack, char* needle) {
	int s = 0;
	int i = 0;
	int n = strlen(haystack);
	int m = strlen(needle);

	if (m == 0) 
		return 0;
	if (m > n)
		return -1;


	while ( i <= n-m){
		s = 0;
		while (haystack[i+s] == needle[s]){
			s++;
			if (s >= m){
				break;
			}
		}

		if (s == m){
			return i;
		}
		i++;
	} 
	return -1;	
}
