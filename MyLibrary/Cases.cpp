# include <vector>
using namespace std;

//-----------------------コピペここから--------------------------

template<typename T>
struct Cases {

	vector<T> fact;

	Cases(int n) : fact(n + 1) {
		fact[0] = 1;
		for (int i = 0; i <= n; i++) {
			fact[i] = fact[i - 1] * i;
		}
	}

	T comb(T n, T r) {

		if (n < r) return T(0);
		if (r == 0) return T(1);

		return fact[n] / fact[r] / fact[n - r];

	}

	T perm(T n, T r) {
		if (n < r) return T(0);
		if (n == r || r == 0) return T(1);
		return fact[n] / fact[n - r];
	}

};

//-----------------------コピペここまで--------------------------