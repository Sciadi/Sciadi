/// this is a general description
///
/// this is a detailed description
struct adj_node {
  int node;
  float weight;
  struct adj_node* next;
};


typedef adj_node* adj_list;

/// this is a general description
///
/// this is a detailed description
typedef struct {
	adj_list* nodes;
	int dim;
} graph;

graph new_graph(int);
void add_arc(graph&, int, int, float);
void add_edge(graph& g, int, int, float);

int get_dim(graph);
adj_list get_adjlist(graph,int);
int get_adjnode(adj_node*);
float get_adjweight(adj_node*);
adj_list get_nextadj(adj_list);



