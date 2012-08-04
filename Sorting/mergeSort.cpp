template<class T> static void merge (vector<T>& v, const int& l, const int& mid, const int& u)
{
  vector<T> tmp(u + 1 - l);
  
  int i, j, k;
  for (i = 0, j = l, k = mid + 1; i < u + 1 - l && j <= mid && k <= u; i++)
  {
    if (v[j] < v[k])
    {
      tmp[i] = v[j++];
    }
    else
    {
      tmp[i] = v[k++];
    }
  }

  while (j <= mid)
  {
    tmp[i++] = v[j++];
  }
  
  while (k <= u)
  {
    tmp[i++] = v[k++];
  }

  // Copy back to v
  for (i = 0, j = l; j <= u; i++, j++)
  {
    v[j] = tmp[i];
  }
}

template<class T> static void divideAndSort (vector<T>& v, const int& l, 
                                            const int& u)
{
  if (l >= u)
  {
    return;
  }

  int mid = (l + u) / 2;
  
  divideAndSort (v, l, mid);
  divideAndSort (v, mid + 1, u);
  merge (v, l, mid, u);
}
template <class T> void mergeSort (vector<T>& v)
{
  divideAndSort (v, 0, v.size() - 1);
}
