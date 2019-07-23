# include <iostream>
using namespace std;

//-----------------------�R�s�y��������--------------------------

/* �g�����[�N���b�h�̌ݏ��@(ax + by = 1 �𖞂���x, y) */
template<typename T>
T extgcd(T a, T b, T& x, T& y) {
	T d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}

/* MOD��@�Ƃ���� */
template<typename T, T MOD = 1000000007>
struct Mint {

	static constexpr T mod = MOD;

	T v;

	/* �R���X�g���N�^�Q */
	Mint() :v(0) {}

	Mint(signed _v) :v(_v) {}

	Mint(long long t) {
		v = t % mod;
		if (v < 0) v += mod;
	}

	/* �ׂ�����v�Z */
	Mint pow(long long k) {
		Mint res(1), tmp(v);
		while (k) {
			if (k & 1) res *= tmp;
			tmp *= tmp;
			k >>= 1;
		}
		return res;
	}

	/* �P�ʌ� */
	static Mint add_identity() { return Mint(0); }
	static Mint mul_identyty() { return Mint(1); }

	/* �t�������߂� */
	// �I�C���[�̒藝
	Mint inv() { return pow(mod - 2); }

	// �g�����[�N���b�h�ݏ��@
	Mint inv_euclid() {
		T x, y;
		extgcd(v, mod, x, y);
		return Mint(x);
	}

	/* ���Z�q�Q */
	Mint& operator+=(Mint a) {
		v += a.v;
		if (v >= mod) v -= mod;
		return *this;
	}

	Mint& operator-=(Mint a) {
		v += mod - a.v;
		if (v >= mod) v -= mod;
		return *this;
	}

	Mint& operator*=(Mint a) {
		v = 1LL * v * a.v % mod;
		return *this;
	}

	Mint& operator/=(Mint a) {
		return (*this) *= a.inv();
		// ���[�N���b�h�̌ݏ��@���g���ꍇ
		// return (*this) *= a.inv_euclid();
	}

	Mint& operator+=(T a) { return (*this) += Mint(a); }
	Mint& operator-=(T a) { return (*this) -= Mint(a); }
	Mint& operator*=(T a) { return (*this) *= Mint(a); }
	Mint& operator/=(T a) { return (*this) /= Mint(a); }

	Mint operator+(Mint a) const { return Mint(v) += a; }
	Mint operator-(Mint a) const { return Mint(v) -= a; }
	Mint operator*(Mint a) const { return Mint(v) *= a; }
	Mint operator/(Mint a) const { return Mint(v) /= a; }

	Mint operator+(T a) const { return Mint(v) += a; }
	Mint operator-(T a) const { return Mint(v) -= a; }
	Mint operator*(T a) const { return Mint(v) *= a; }
	Mint operator/(T a) const { return Mint(v) /= a; }

	Mint operator-() const { return v ? Mint(mod - v) : Mint(v); }

	bool operator==(const Mint a) const { return v == a.v; }

	bool operator!=(const Mint a) const { return v != a.v; }

	bool operator<(const Mint a) const { return v < a.v; }

	bool operator>(const Mint a) const { return v > a.v; }

	/* �g�ݍ��킹 */
	static Mint comb(long long n, int k) {
		Mint num(1), dom(1);
		for (int i = 0; i < k; i++) {
			num *= Mint(n - i);
			dom *= Mint(i + 1);
		}
		return num / dom;
	}

};

template<typename T, T MOD> constexpr T Mint<T, MOD>::mod;

/* ostream�ŏo�͂ł���悤�� */
template<typename T, T MOD>
ostream& operator<<(ostream &os, Mint<T, MOD> m) { os << m.v; return os; }

//-----------------------�R�s�y�����܂�--------------------------