#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ", "; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "{"; for (T i : v) {_print(i); cerr << ", ";} cerr << "}";}
template <class T> void _print(set <T> v) {cerr << "["; for (T i : v) {_print(i); cerr << ", ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T, size_t size> void _print(const T (&array)[size]){cerr << "{"; for(size_t i = 0; i < size; ++i) { _print(array[i]); if (i < size - 1) cerr << ", "; } cerr << "}";}

// standard input and output template
template<typename... T>
void in(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void out(T&&... args) {
    ((cout << args << " "), ...);
}

template<typename... T>
void outl(T&&... args) {
    ((cout << args << endl), ...);
}

int maxSubArraySum(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for(int k=i;k<=j;k++){
                cout<<v[k]<<" ";
                sum += v[k];
            }
            cout<<" sum = "<<sum<<endl;
            maxSum = max(maxSum, sum);
            cout<<endl;
        }
    }
    return maxSum;
}
int maxSubArraySumBetter(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        int currSum = 0;
        for (int j = i; j < n; j++) {
            currSum += v[j];
            maxSum = max(maxSum, currSum);
            cout<< "currSum: "<< currSum<<" maxSum: "<< maxSum<<" i: "<< i<<" j: "<< j<<endl;
        }
        currSum -= v[i];
    }
    return maxSum;
}

//kadane's algorithm:-
// not carrying any sum which has value less than zero 
int maxSubArraySumOptimal(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int maxSum = INT_MIN;
    int currSum = 0;
    int start=0,end=0;
    for (int i = 0; i < n; i++) {
        if(currSum ==0) start = i;
        currSum += v[i];
        if(currSum < 0){
            currSum = 0;
        }
        if(currSum > maxSum)
        {
             maxSum = currSum;
             end =i;
        }
    }
    cout<<"Index of subarray for largest sum"<<endl;
    cout<<"start =" << start <<" end =" << end <<endl;
    return maxSum;
}
// nt maxSum = INT_MIN;
//         int currSum =0;
//         int n = nums.size();
//         for(int i=0;i<n;i++)
//         {
//             currSum+=nums[i];
//             maxSum = max(maxSum,currSum);
//             if(currSum<0) currSum=0;
//         }
//         return maxSum;
void solve() {
    // vector<int> v = {1,2,3,4,5};
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    // vector<int> v = {-1, 1, 1};
    // vector<int> v = {2,3,5};

    // auto brute = maxSubArraySum(v);
    // debug(brute);
    // auto better = maxSubArraySumBetter(v);
    // debug(better);
    auto optimal = maxSubArraySumOptimal(v);
    debug(optimal);

    // int arr2[] = {1,2,3,4,5};
    // right_rotate_brute(arr2,end(arr2)-begin(arr2), k);
    // debug(arr2);

    // int arr3[] = {1,2,3,4,5};
    // right_rotate_optimal(arr3,end(arr3)-begin(arr3), k);
    // debug(arr3);
    
    // debug(arr1);
    // for0(i,arr_size1) out(arr1[i]);
}

int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("../../../input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("../../../output.txt", "w", stdout);
    // for error output to error.txt
    freopen("../../../error.txt", "w", stderr);
    #endif

    // Call the test function to debug print all data structures
    // test_debug();  

    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
    //to run this always have 1 in input.txt

    return 0;
}