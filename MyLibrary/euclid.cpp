//-----------------------コピペここから--------------------------

/* ユークリッドの互除法で最大公約数を求める */
template<typename T = long long>
T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }

/* 拡張ユークリッドの互除法(ax + by = 1 を満たすx, y) */
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

//-----------------------コピペここまで--------------------------