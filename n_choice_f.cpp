#include <iostream>

long long n_choice_f(long n, long f)
{
    long long numerator = 1;
    long long denominator = 1;

    for (int i = 0; i < f; i++)
    {
        numerator *= (n - i);
        denominator *= (i + 1);
    }

    return numerator / denominator;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <n> <k>" << std::endl;
        return 1;
    }

    long long n = std::atoll(argv[1]);
    long long k = std::atoll(argv[2]);

    long long choice = n_choice_f(n, k);
    std::cout << choice << std::endl;

    return 0;
}