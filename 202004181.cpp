class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here'
		if (n == 0)
		{
			return 0;
		}
		vector<int> B(n, 0);
		vector<int> C(n, 0);
		B[0] = A[0];
		C[n - 1] = A[n - 1];
		for (int i = 1, j = n - 2; i < n, j >= 0; i++, j--)
		{
			if (A[i] > B[i - 1])
			{
				B[i] = A[i];
			}
			else
			{
				B[i] = B[i - 1];
			}
			if (A[j] > C[j + 1])
			{
				C[j] = A[j];
			}
			else
			{
				C[j] = C[j + 1];
			}
		}
		int ret = 0;
		for (int k = 0; k < n - 1; k++)
		{
			int tmp = max(B[k], C[k + 1]) - min(B[k], C[k + 1]);
			if (tmp > ret)
			{
				ret = tmp;
			}
		}
		return ret;

	}
};