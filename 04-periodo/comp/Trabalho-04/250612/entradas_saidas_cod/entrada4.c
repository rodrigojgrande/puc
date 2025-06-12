int main() {
	int a, b;
	b = 60;
	a = 0;
	while(b > a){
		if(a < 10)
			a = a+(b/3);
		else if(a < 20)
			a = a+b/6;
			else
				a = a+1;
			endif
		endif
	}
}
