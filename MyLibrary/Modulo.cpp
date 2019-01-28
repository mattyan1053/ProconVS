class Modulo {
private:
	long long num;
	long long mod;

public:
	Modulo(long long _mod) :
		num(0),
		mod(_mod)
	{

	}

	Modulo(long long _num, long long _mod) :
		num(_num),
		mod(_mod)
	{
		num %= mod;
		num += mod;
		num %= mod;
	}

	Modulo(const Modulo &o) :
		num(o.num),
		mod(o.mod)
	{
	}

	// 表示
	long long get_num() {
		return num;
	}

	// MODのリセット
	void reset_mod(long long _mod) {
		mod = _mod;
		num %= mod;
	}

	// 演算子オーバーロード

	// =
	Modulo &operator=(Modulo obj) {
		num = obj.num;
		return *this;
	}

	Modulo &operator=(long long obj) {
		num = obj;
		num %= mod;
		num += mod;
		num %= mod;
		return *this;
	}

	Modulo &operator=(int obj) {
		num = (long long)obj;
		num %= mod;
		num += mod;
		num %= mod;
		return *this;
	}

	// +
	Modulo operator+(Modulo obj) {
		return Modulo((num + obj.num) % mod, mod);
	}
	Modulo operator+(long long obj) {
		obj %= mod;
		obj += mod;
		obj %= mod;
		return Modulo((num + obj) % mod, mod);
	}
	Modulo operator+(int obj) {
		long long new_obj = (long long)obj;
		new_obj %= mod;
		new_obj += mod;
		new_obj %= mod;
		return Modulo((num + new_obj) % mod, mod);
	}

	// -
	Modulo operator-(Modulo obj) {
		long long tmp = num;
		tmp -= obj.num;
		tmp += mod;
		tmp %= mod;
		return Modulo(tmp, mod);
	}
	Modulo operator-(long long obj) {
		long long tmp = num;
		obj %= mod;
		obj += mod;
		obj %= mod;
		num -= obj;
		num += mod;
		num %= mod;
		return Modulo(tmp, mod);
	}
	Modulo operator-(int obj) {
		long long new_obj = (long long)obj;
		long long tmp = num;
		new_obj %= mod;
		new_obj += mod;
		new_obj %= mod;
		tmp -= new_obj;
		tmp += mod;
		tmp %= mod;
		return Modulo(tmp, mod);
	}

	// *
	Modulo operator*(Modulo obj) {
		long long tmp = num;
		tmp *= obj.num;
		tmp %= mod;
		return Modulo(tmp, mod);
	}
	Modulo operator*(long long obj) {
		long long tmp = num;
		tmp *= obj;
		tmp %= mod;
		return Modulo(tmp, mod);
	}
	Modulo operator*(int obj) {
		long long tmp = num;
		long long new_obj = (long long)obj;
		tmp *= new_obj;
		tmp %= mod;
		return Modulo(tmp, mod);
	}

	// /
	Modulo operator/(Modulo obj) {
		long long tmp = num;
		tmp *= mod_inv(obj.num);
		tmp %= mod;
		return Modulo(tmp, mod);
	}
	Modulo operator/(long long obj) {
		long long tmp = num;
		tmp *= mod_inv(obj);
		tmp %= mod;
		return Modulo(tmp, mod);
	}
	Modulo operator/(int obj) {
		long long tmp = num;
		tmp *= mod_inv((long long)obj);
		tmp %= mod;
		return Modulo(tmp, mod);
	}

	// +=
	Modulo &operator+=(Modulo obj) {
		num += obj.num;
		num %= mod;
		return *this;
	}
	Modulo &operator+=(long long obj) {
		obj %= mod;
		obj += mod;
		obj %= mod;
		num += obj;
		num %= mod;
		return *this;
	}
	Modulo &operator+=(int obj) {
		long long new_obj = (long long)obj;
		new_obj %= mod;
		new_obj += mod;
		new_obj %= mod;
		num += new_obj;
		num %= mod;
		return *this;
	}

	// -=
	Modulo &operator-=(Modulo obj) {
		num -= obj.num;
		num += mod;
		num %= mod;
		return *this;
	}
	Modulo &operator-=(long long obj) {
		obj %= mod;
		obj += mod;
		obj %= mod;
		num -= obj;
		num += mod;
		num %= mod;
		return *this;
	}
	Modulo &operator-=(int obj) {
		long long new_obj = (long long)obj;
		new_obj %= mod;
		new_obj += mod;
		new_obj %= mod;
		num -= new_obj;
		num += mod;
		num %= mod;
		return *this;
	}

	// *=
	Modulo &operator*=(Modulo obj) {
		num *= obj.num;
		num %= mod;
		return *this;
	}
	Modulo &operator*=(long long obj) {
		num *= obj;
		num %= mod;
		return *this;
	}
	Modulo &operator*=(int obj) {
		long long new_obj = (long long)obj;
		num *= new_obj;
		num %= mod;
		return *this;
	}

	// /=
	Modulo &operator/=(Modulo obj) {
		num *= mod_inv(obj.num);
		num %= mod;
		return *this;
	}
	Modulo &operator/=(long long obj) {
		num *= mod_inv(obj);
		num %= mod;
		return *this;
	}
	Modulo &operator/=(int obj) {
		long long new_obj = (long long)obj;
		num *= mod_inv(new_obj);
		num %= mod;
		return *this;
	}

	// ==
	bool operator==(Modulo obj) {
		return num == obj.num && mod == obj.mod;
	}

	// 逆元を求める
	long long mod_inv(long long value) {

		long long b = mod, u = 1, v = 0;

		while (b) {
			long long t = value / b;
			value -= t * b;
			swap(value, b);
			u -= t * v;
			swap(u, v);
		}
		u %= mod;
		if (u < 0) u += mod;

		return u;
	}

	// a^n の計算

	Modulo mod_pow(long long n) {
		long long a = num;
		long long res = 1;
		while (n > 0) {
			if (n & 1) res = res * a % mod;
			a = a * a % mod;
			n >>= 1;
		}
		return Modulo(res, mod);
	}

};