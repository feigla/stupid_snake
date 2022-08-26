int stringlen(char *str)
{
	char *tmp;
	tmp = str;
	while(*tmp) {
		tmp++;
	}
	return tmp - str;
}
