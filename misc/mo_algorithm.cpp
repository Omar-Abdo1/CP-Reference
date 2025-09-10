
void remove(idx);  // TODO: remove value at idx from data structure
void add(idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

int block_size; // sqrt(n)

struct Query
{
    int l, r, idx;
    bool operator<(Query other) const
    {
        if(l/block_size != other.l/block_size)
         return l<other.l;
  return (l /block_size & 1) ? (r<other.r) : (r>other.r);    
    }
};

vector<long long> mo_s_algorithm(vector<Query> queries) // 0 based
{

// n*sqrt(n) + q*sqrt(n)   for offline queries queries are independent
// n*sqrt(n) -> right pointer 
// q*sqrt(n) -> left pointer

    vector<long long> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = queries[0].l;
    int cur_r = l-1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries)
    {
        while (cur_l > q.l)
        {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r)
        {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l)
        {
            Delete(cur_l);
            cur_l++;
        }
        while (cur_r > q.r)
        {
            Delete(cur_r);
            cur_r--;
        }
        answers[q.idx] = ans ;
    }
    return answers;
}

