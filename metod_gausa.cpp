double mGaussian(double** a, double* b, double* c, int size)
		{
			double _a[size][size];

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
                    if(i==j)_a[i][j] = 1;
                    else _a[i][j] = 0;
				}
			}

			for (int i = 0; i < size; i++)
			{
				double ap = a[i][i];
				for (int j = 0; j < size; j++)
				{
					if (ap != 0 && ap != 1)
					{
						_a[i][j] /= ap;
						a[i][j] /= ap;
					}
				}
				double ci[size];
				for (int j = 0; j < size; j++)
				{
					ci[j] = a[j][i];
					if (j != i)
					{
						for (int k = 0; k < size; k++)
						{
							_a[j][k] -= _a[i][k] * ci[j];
							a[j][k] -= a[i][k] * ci[j];
						}
					}
				}
			}
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					c[i] += _a[i][j] * b[j];
				}
			}
		}