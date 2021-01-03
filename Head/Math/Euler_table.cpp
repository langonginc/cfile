ll phi[1900900],prime[1900900],tot;

void EulerTable(ll n)
{
  phi[1]=1;
  for(ll i=2;i<=n;i++)
  {
    if(phi[i]==0)
    {
      phi[i]=i-1,prime[tot++]=i;
    }
    for(ll j=0;j<tot && i*prime[j]<=n;j++)
    {
      if(i%prime[j]==0)
      {
        phi[i*prime[j]]=phi[i]*prime[j];
        break;
      }
      else
      {
        phi[i*prime[j]]=phi[i]* (prime[j]-1);
      }
    }
  }
}
