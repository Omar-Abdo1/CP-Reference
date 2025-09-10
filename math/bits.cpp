bool getBit(ll num, int idx) {
	return ((num >> idx) & 1);
}
 
ll setBit(ll num, int idx, bool val) {
	return val ? (num | (1LL << idx)) : (num & ~(1LL << idx));
}
 
ll flipBit(ll num, int idx) {
	return (num ^ (1LL << idx));
}
 
ll leastBit(ll num) {
	return (num & -num);
}
 
//num%mod, mod is a power of 2
ll Mod(ll num, ll mod) {
	return (num & mod - 1);
}
 
bool isPowerOfTwo(ll num) {
	return (num & num - 1) == 0;
}
 
int turnOnLastZero(int S) {
	return S | S + 1;
}
 
int turnOffLastBit(int S) {
	return S & S - 1;
}
 
int turnOnLastConsecutiveZeroes(int S) {
	return S | S - 1;
}
 
int turnOffLastConsecutiveBits(int S) {
	return S & S + 1;
}
 
