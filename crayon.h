#ifndef CRAYON_H
#define CRAYON_H
#include<bits/stdc++.h>
#define ll long long
#define ld long double
struct crayon{
		void seed(){
			srand(time(0));
		}
		ll cintrand(ll a, ll b){
			return rand()%(b-a+1)+a;
		}
		bool cboolrand(){
			return rand()%2;
		}
};
#endif
