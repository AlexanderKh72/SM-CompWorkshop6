#pragma once
#include "Sample.h"

/// Хранение и моделирование выборки методом Ченга.
/** В конструкторе класса ChengSample передаётся значение параметра \f$m\f$, используемого для моделирования выборки методом Ченга.
 */
class ChengSample : public Sample {
public:
    ChengSample(int mm) : Sample(), m(mm) {}
    /**< Конструктор ChengSample::ChengSample(mm) принимает на вход целочисленный положительный параметр mm, используемый при моделировании выборки в функции ChengSample::simulate. */
    void simulate(const Distribution& distr, int sz, std::mt19937& gen) override;
    /**< См. Sample::simulate. Для моделирования распределения distr используется метод Ченга. */
private:
    int m;
};

