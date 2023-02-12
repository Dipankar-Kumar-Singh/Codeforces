 ll n;
    
    cin>>n;
    ll N=n+1;
    vll v(n);
    cin>>v;
    map<ll,ll>mpp;
    fl(i,n)mpp[v[i]]++;
    vll ans;
    ll xx=0;
    set<ll>st;
    for(int i=0;i<n;i++)
    {
        mpp[v[i]]--;
        st.insert(v[i]);
        while(st.find(xx)!=st.end())
        {
            
            xx++;
        }
        if(mpp[xx]==0)
        {
            st.clear();
            ans.pb(xx);
            xx=0;
        }
    }
    cout<<ans.size()<<"\n";
    cout<<ans<<"\n";