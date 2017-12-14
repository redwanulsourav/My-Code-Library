#include <iostream>
#include <cstdio>

using namespace std;
typedef unsigned long long ull;
class dummy_int{
	private:
		ull val;
		bool sign;
	public:
		dummy_int(){
			val = sign = 0;
		}
		dummy_int(bool _sign, ull _val){
			val = _val;
			sign = _sign;
		}

		dummy_int operator+(const dummy_int &b) const{
			dummy_int ans;

			if(this->sign && !b.sign){
				ans.sign = false;
				ans.val = this->val + b.val;
			}
			if(!this->sign && b.sign){
				if(this->val >= b.val){
					ans.sign = false;
					ans.val = this->val - b.val;
				}
				else{
					ans.sign = true;
					ans.val = b.val - this->val;
				}
			}

			if(this->sign && !b.sign){
				if(this->val > b.val){
					ans.sign = true;
					ans.val = this->val - b.val;
				}
				else{
					ans.sign = false;
					ans.val = b.val - this->val;
				}	
			}

			if(this->sign && b.sign){
				ans.sign = true;
				ans.val = this->val + b.val;
			}
			return ans;
		}

		dummy_int operator-(const dummy_int &b)const {
			return this->operator+(dummy_int(!b.sign,b.val));
		}

		dummy_int operator+(const ull &a) const{
			return this->operator+(dummy_int(false,a));
		}
		dummy_int operator-(const ull &a) const{
			return this->operator-(dummy_int(false,a));
		}

		dummy_int operator*(const dummy_int &a) const{
			dummy_int ans;
			if((a.sign || sign) && !(a.sign && sign)){
				ans.sign = true;
				ans.val = val * a.val;
			}
			else{
				ans.sign = a.sign;
				ans.val = val * a.val;
			}
		}

		dummy_int operator*(const ull a){
			dummy_int ans;
			ans.sign = sign;

			ans.val = val * a;

			return ans;
		}
		void print(){
			if(sign)	printf("-");
			printf("%llu\n",val);
		}
};

int main(){

}