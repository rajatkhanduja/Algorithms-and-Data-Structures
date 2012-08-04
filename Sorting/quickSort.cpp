template <class T> static void arrangeIncreasing (T &a, T &b, T &c)
{
  if (a > b)
  {
    std::swap (a, b);  // now, a < b
  }

  if (b > c)
  {
    std::swap (b, c);  // now, b < c
  }

  if (a > b)
  {
    std::swap (a, b);
  }
}

template <class T> void quickSort (vector<T> &v, const int& l, const int& u)
{ 
  if (l >= u)
  {
    return;
  }

  if (l + 1 == u)
  {
    if (v[l] > v[u])
    {
      std::swap (v[l], v[u]);
    }
    return;
  }

  int mid = (l + u) / 2;
  arrangeIncreasing (v[l], v[mid], v[u]);
  std::swap (v[mid], v[u]);
  
  int i = l, j = u - 1;

  while (i < j)
  {
    while (v[i] < v[u])
      i++;

    while (!(v[j] < v[u]))
      j--;

    std::swap (v[i], v[j]);
  }
  
  std::swap (v[i], v[u]);
  quickSort (v, l, j);
  quickSort (v, i, u);
  merge (v, l, j, u);
}

template <class T> void quickSort (vector<T>& v)
{
  quickSort (v, 0, v.size() - 1); 
}
