const int N = 1e6;
bool prime[N];

void  sieve_v2(){
	for (int i = 0; i < N; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 4; i < N; i += 2){
		prime[i] = 0;
	}
	for (int i = 3; i * i < N; i += 2){
		if (prime[i]){
			for (int j = i * i; j < N; j += i + i){
				prime[j] = 0;
			}
		}
	}
}

void Prime_Factors_Faster(int n){
	vector<int>primes;
	sieve_v2();
	for (int i = 2; i < N; i++){
		if (prime[i]){
			primes.push_back(i);
		}
	}
	
	int idx = 0;
	while (idx < primes.size() && primes[idx] * primes[idx] <= n){
		int cnt = 0;
		while (n % primes[idx] == 0){
			n /= primes[idx];
			cnt++;
		}
		if (cnt) cout << primes[idx] << " " << cnt << endl;
		idx++;
	}
	if (n>1){
		cout << n << " " << 1 << endl;
	}
}
