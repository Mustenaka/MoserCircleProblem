#include <iostream>

#if defined(__clang__)
typedef long ll;
#else
typedef long long ll;
#endif

/**
 * @brief 计算n中choice的f个数字
 * @param n n
 * @param f f
 * @return 排列组合全部数字
 */
ll n_choice_f(ll n, ll f)
{
    ll numerator = 1;
    ll denominator = 1;

    for (ll i = 0; i < f; i++)
    {
        numerator *= (n - i);
        denominator *= (i + 1);
    }

    return numerator / denominator;
}

/**
 * @brief 计算一个圆内，被线段切割产生了多少个内部区域
 * @param n 圆内线段数
 * @return 封闭区域数量，注意圆本身不计算
 */
ll moser_circle(ll n)
{
    // vertices count: (n + n_choice_4)
    // edge: (n_choice_2 + 2 * n_choice_4 + n)
    // area: f = e - v + 1

    ll n_choice_2 = n_choice_f(n, 2);
    ll n_choice_4 = n_choice_f(n, 4);

    return n_choice_2 + n_choice_4 + 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <n> " << std::endl;
        return 1;
    }

    ll n = std::atoll(argv[1]);

    ll area_count = moser_circle(n);

    std::cout << area_count << std::endl;

    return 0;
}
