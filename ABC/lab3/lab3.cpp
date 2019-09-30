#include <chrono>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <sys/time.h>


struct timeval tv1,tv2,dtv;

struct timezone tz;

void time_start() { 
	gettimeofday(&tv1, &tz); 
}

double time_stop(){ gettimeofday(&tv2, &tz);

  dtv.tv_sec= tv2.tv_sec -tv1.tv_sec;

  dtv.tv_usec=tv2.tv_usec-tv1.tv_usec;

  if(dtv.tv_usec<0) { dtv.tv_sec--; dtv.tv_usec+=1000000; }

  return dtv.tv_sec*1000+dtv.tv_usec/1000;

}

const uint64_t get_time(){
	uint32_t high, low;
	__asm__ __volatile__(
		"rdtsc\n"
		"movl %%edx, %0\n"
		"movl %%eax, %1\n"
		: "=r" (high), "=r" (low)
		:: "%rax", "%rbx", "%rcx", "%rdx"
	);
	return ((uint64_t)high << 32) | low;
}


double sinx(double x)
{
    double n = x;
    double sum = 0.0;
    int i = 1;
 
    do
    {
        sum += n;
        n *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
        i++;
    }
    while (fabs(n) > 0.000000001);
 
    return sum;
}



int main(void){
	int x;
	clock_t start1, stop;
	double sum_of_MatO, sum_of_MatO1, sum_of_MatO2;
	uint64_t t1, t2, sum_of_MatO3;
	std::size_t i, j;
	double res;
	std::vector<double> MatO, MatO1, MatO2;
	std::vector<uint64_t> MatO3;
	
	std::cout << "Inpunt x: " << std::endl;
	std::cin >> x;
	
	for(j = 0; j < 20; j++){
		auto start = std::chrono::system_clock::now();
		for(i = 0; i < 10000000; i++)
			sinx(x);
		std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
		MatO.push_back(dur.count());
	}
	auto start = std::chrono::system_clock::now();
		for(i = 0; i < 10000000; i++)
			sinx(x);
		std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
	
	
	
	for(j = 0; j < 20; j++){
		start1 = clock();
		for(i = 0; i < 10000000; i++)
			sinx(x);
		stop = clock();
		MatO1.push_back((double)(stop-start1)/CLOCKS_PER_SEC);
	}
	start1 = clock();
	for(i = 0; i < 10000000; i++)
		sinx(x);
	stop = clock();
	
	
	for(j = 0; j < 20; j++){
		time_start();
		for(i = 0; i < 10000000; i++)
			sinx(x);
		res = time_stop();
		MatO2.push_back(res/1000);
	}
	time_start();
	for(i = 0; i < 10000000; i++)
		sinx(x);
	res = time_stop();
	
	
	for(j = 0; j < 20; j++){
		t1 = get_time();
		for(i = 0; i < 10000000; i++)
			sinx(x);
		t2 = get_time();
		MatO3.push_back(t2-t1);
	}
	t1 = get_time();
	for(i = 0; i < 10000000; i++)
		sinx(x);
	t2 = get_time();
	
	
	
	
	for (auto& n : MatO)
    	sum_of_MatO += n;
	for (auto& n : MatO1)
    	sum_of_MatO1 += n;
	for (auto& n : MatO2)
    	sum_of_MatO2 += n;
	for (auto& n : MatO3)
    	sum_of_MatO3 += n;
	
	std::cout << "Sin: " << std::setprecision(30) << sinx(x) << std::endl << std::endl;
	
	std::cout << "Time native(Chono): " << std::setprecision(10) << dur.count() << " seconds" << std::endl;
	std::cout << "Абсолютная погрешность(Chrono): "  << fabs(sum_of_MatO/20 - dur.count())<< std::endl;
	std::cout << "Относительная погрешность(Chrono): "  << fabs((sum_of_MatO/20 - dur.count()) / dur.count())<< std::endl << std::endl;
	
	std::cout << "Time native(Clock): " << std::setprecision(10) << (double)(stop-start1)/CLOCKS_PER_SEC << " seconds" << std::endl;
	std::cout << "Абсолютная погрешность(Clock): "  << fabs(sum_of_MatO1/20 - ((double)(stop-start1)/CLOCKS_PER_SEC)) << std::endl;
	std::cout << "Относительная погрешность(Clock): "  << fabs((sum_of_MatO1/20 - ((double)(stop-start1)/CLOCKS_PER_SEC)) / ((double)(stop-start1)/CLOCKS_PER_SEC)) << std::endl << std::endl;
	
	std::cout << "Time native(GetTimeofDay): " << std::setprecision(10) << res/1000 << " seconds" << std::endl;
	std::cout << "Абсолютная погрешность(GetTimeofDay): "  << fabs(sum_of_MatO2/20 - res/1000)<< std::endl;
	std::cout << "Относительная погрешность(GetTimeofDay): "  << fabs((sum_of_MatO2/20 - res/1000) / (res/1000))<< std::endl << std::endl;
	
	std::cout << "Clock native(TSC): "  << t2 - t1 << " ticks " << std::endl;
	std::cout << "Абсолютная погрешность(TSC): "  << abs(sum_of_MatO3/20 - (t2 - t1))<< std::endl;
	std::cout << "Относительная погрешность(TSC): "  << abs((sum_of_MatO3/20 - (t2 - t1)) / (t2 - t1))<< std::endl << std::endl;
	return 0;
}
