import networkx as nx
import random

# Number of nodes and edges
num_nodes = 40
num_edges = 70

# Generate a random graph
G = nx.gnm_random_graph(num_nodes, num_edges)

# Ensure the graph is connected
while not nx.is_connected(G):
    G = nx.gnm_random_graph(num_nodes, num_edges)

# Add random weights to the edges
for edge in G.edges():
    G[edge[0]][edge[1]]['weight'] = random.randint(1, 10)

# Print the edges with weights
for edge in G.edges(data=True):
    print(edge)

# Visualization
import matplotlib.pyplot as plt

pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, font_weight='bold', node_size=700, node_color='skyblue', font_size=8, edge_color='gray', width=1, alpha=0.7)

# Draw edge labels
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)

plt.show()