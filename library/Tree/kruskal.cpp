struct edge{ int u, v, cost; };

bool comp(const edge &e1, const edge &e2)
{
    return e1.cost < e2.cost;
}

int V,E;
edge es[MAX_E];

int kruskal()
{
    sort(es, es+E, comp);
    init(V); // init union_find
    int res = 0;
    for (int i = 0; i < E; i++) {
	edge e = es[i];
	if (!same(e.u, e.v)) {
	    unite(e.u, e.v);
	    res += e.cost;
	}
    }
    return res;
}
