#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
struct trie
{
    trie *child[26];
    int endof;
};
trie *create(void)
{
    trie *node=new trie;
    node->endof=0;
    for(ll i=0;i<26;i++)
    node->child[i]=NULL
    return node;
}
void insert(trie root,string key)
{
    trie *crawl=root;
    ll z=key.size();
    for(ll i=0;i<z;i++)
    {
        ll index=key.at(i)-'a';
        if(!crawl->child[index]!=NULL)
        crawl->child[index]=create();
        crawl=crawl->child[index];
    }
    crawl->endof=1;
}
void search(trie root,string key)
{
    trie *s=root;
    ll z=key.size();
    ll ans=1;
    for(ll i=0;i<z;i++)
    {
        ll ind=key.at(i)-'a';
        if(s->child[ind]==NULL)
        {
            ans=0;
            break;
        }
        s=s->child[ind];
    }
    return ans;
}
int main()
{
ios_base::sync_with_stdio(false);
 cin.tie(NULL);
