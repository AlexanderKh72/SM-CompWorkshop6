#include "Sample.h"

int Sample::size() const
{
    int sample_size = 0;
    for (int i = 0; i < nstates; sample_size += sample[i++]);
    return sample_size;
}
