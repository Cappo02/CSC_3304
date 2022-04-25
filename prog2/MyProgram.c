#include <stdio.h>

long a = 10000, b, c = 2800, d, e, f[2801], g;

void terseVersion() {

	for (;b-c;) f[++b]=a/5;
		for(;d=0,g=c*2;c-=14,printf("%.4d",e+d/a),e=d%a)
			for(b=c;d+=f[b]*a,f[b]=d%--g,d/=g--,--b;d*=b);

}

void verboseVersion() {

	a = 10000;
	b = 0;
	c = 2800;
	d = 0;
	e = 0;
	f[2801];
	g = 0;

	while(b - c < 0) {

		b = b + 1;
		f[b] = a / 5;

	}
	
	while(c > 0) {

		g = c * 2;
		e = d % a;
		b = c;

		d = d + f[b] * a;
		g = g - 1;
		f[b] = d % g;
		d = d / g;
		g = g - 1;

		while(b = b - 1) {

			d = d * b;
			d = d + f[b] * a;
			g = g - 1;
			f[b] = d % g;
			d = d / g;
			g = g - 1;

		}

		printf("%.4d", e + d / a);
		c = c - 14;

	}

}

main() {

	printf("Terse Verison\n");
	terseVersion();
	printf("\n");
	printf("\n");
	printf("Verbose Version\n");
	verboseVersion();
	printf("\n");

}
