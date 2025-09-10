const int MAXN = 1e6;
const int MOD = 1e9 + 7;

ll fac[MAXN + 1];
ll inv[MAXN + 1];

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n>>=1;
	}
	return res;
}

void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

ll NcR(int n, int r) { return fac[n] * inv[r] % MOD * inv[n - r] % MOD; } // NcR

ll NpR(int n, int r) { return fac[n] *  inv[n - r] % MOD; } // NpR

ll nCr(ll n, ll r){
	ll ans = 1;
	ll div = 1; // r! 
	for (ll i = r + 1; i <= n; i++){
		ans = ans * i;
		ans /= div;
		div++;
	}
	return ans;
}
// NPR 
ll nPr(ll n, ll r){
	ll ans = 1;
	for (ll i = (n - r) + 1; i <= n; i++){
		ans *= i;
		ans %= mod;
	}
	return ans;
}





