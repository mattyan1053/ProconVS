//-----------------------�R�s�y��������--------------------------

/* ���[�N���b�h�̌ݏ��@�ōő���񐔂����߂� */
template<typename T = long long>
T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }

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

//-----------------------�R�s�y�����܂�--------------------------