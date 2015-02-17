/*
 * d=2
 * n=200
 * m=150
 * c=1.33
 * maxlen=2
 * minklen=1
 * maxklen=14
 * minchar=45
 * maxchar=121
 * loop=0
 * numiter=828
 * seed=0
 */

static int g[] = {
	86, -1, -1, 53, 36, -1, 0, 62, -1, 5,
	87, 132, 0, -1, 42, 103, 81, 89, 125, 72,
	8, -1, 34, 70, 46, 132, 13, -1, -1, 145,
	76, 120, 100, 138, 37, -1, 136, 24, 93, -1,
	36, 88, 100, 29, -1, 82, 120, -1, 126, 148,
	149, 43, 87, 95, 83, 138, -1, 6, -1, 104,
	24, 0, 0, 128, 139, 0, 137, 54, -1, 0,
	77, 42, 0, -1, 88, 23, 29, 108, 70, 149,
	-1, 93, 20, -1, 25, 55, 0, 20, 72, 122,
	-1, -1, 0, 144, 73, 6, 11, 7, 42, 112,
	92, 94, 80, 50, 66, 23, 8, 74, -1, 56,
	136, 53, 0, 60, -1, 3, -1, 99, 149, 40,
	98, 118, 81, 0, 50, 115, -1, -1, 86, 9,
	21, 26, 1, 0, 117, 9, 36, 91, 35, 41,
	23, 75, 89, 35, 0, 147, 86, 7, 115, -1,
	49, 107, 5, 89, 3, 11, -1, 17, 16, -1,
	29, 35, -1, 95, 110, 96, 43, 42, 121, -1,
	46, 83, -1, 0, 147, 126, 24, -1, 28, 109,
	82, 43, 12, 82, -1, -1, -1, 0, 35, 12,
	86, 92, -1, 146, 96, 58, 93, 143, -1, -1,
};

static int T0[] = {
	196, 103, 27, 185, 60, 0, 58, 36, 180, 118,
	101, 180, 61, 125, 144, 167, 140, 104, 131, 195,
	176, 62, 79, 175, 195, 103, 116, 194, 122, 73,
	44, 119, 128, 23, 56, 188, 23, 114, 24, 156,
	32, 78, 136, 46, 3, 32, 165, 95, 136, 97,
	90, 65, 111, 121, 40, 106, 25, 108, 53, 99,
	181, 49, 18, 110, 72, 74, 50, 48, 141, 27,
	4, 125, 105, 92, 171, 60, 124, 1, 72, 96,
	178, 59, 58, 61, 0, 185, 12, 176, 111, 121,
	49, 170, 70, 48, 43, 82, 178, 157, 34, 62,
	137, 148, 110, 160, 96, 11, 50, 22, 12, 74,
	71, 143, 133, 129, 4, 86, 67, 168, 62, 130,
	41, 63, 101, 63, 112, 96, 146, 90, 5, 132,
	153, 95, 32, 15, 7, 80, 26, 57, 103, 191,
	83, 126, 134, 169, 55, 90, 55, 74, 58, 69,
	5, 99, 132, 58,
};

static int T1[] = {
	87, 14, 91, 162, 194, 198, 131, 1, 89, 2,
	154, 17, 98, 25, 7, 121, 145, 178, 28, 70,
	94, 135, 77, 129, 134, 137, 69, 128, 88, 126,
	114, 175, 92, 5, 89, 87, 3, 20, 88, 44,
	174, 194, 14, 73, 171, 21, 194, 117, 151, 175,
	139, 45, 110, 17, 127, 196, 106, 148, 124, 194,
	26, 190, 169, 118, 195, 59, 157, 150, 31, 197,
	147, 6, 143, 161, 79, 67, 134, 68, 163, 61,
	104, 124, 56, 39, 115, 99, 140, 101, 63, 91,
	124, 4, 134, 110, 132, 61, 150, 96, 116, 167,
	80, 174, 115, 169, 14, 184, 24, 47, 4, 188,
	60, 109, 64, 68, 148, 179, 168, 41, 80, 183,
	84, 156, 187, 18, 18, 119, 79, 169, 168, 148,
	88, 0, 122, 3, 169, 88, 139, 146, 88, 144,
	86, 148, 5, 150, 17, 105, 81, 137, 98, 113,
	120, 182, 69, 107,
};

static int
perfhash(const unsigned char *key, int len)
{
	int i;
	int n;
	unsigned f0, f1;
	const unsigned char *kp = key;

	if (len < 1 || len > 14)
		return -1;

	for (i=-45, n=0, f0=f1=0; n < len; ++n) {
		int c = kp[n];
		c = tolower(c);
		if (c < 45 || c > 121)
			return -1;
		f0 += T0[i + c];
		f1 += T1[i + c];
		i += 77;
		if (i >= 109)
			i = -45;
	}

	f0 %= 200;
	f1 %= 200;

	return (g[f0] + g[f1]) % 150;
}
