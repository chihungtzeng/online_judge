import java.io.*;
import java.util.*;

class Main{
	static void removeEdge(Node V[], int id1,int id2){
		V[id1-1].removeNeighbor(id2);
		V[id2-1].removeNeighbor(id1);
	} 
	static Node[] findMI(Node V[]){
		int i,j;
		Node V1[] = new Node[V.length];
		Node V2[] = new Node[V.length];
		for(i=0;i<V.length;i++){
			V1[i] = V[i].clone();
			V2[i] = V[i].clone();
		}
		/*case 1: color V[0] with BLACK*/
		V1[0].color = Node.BLACK;
		for(i=0;i<V1[0].getDegree();i++){
			
		}		
		
		/*case 1: color V[0] with WHITE*/
		
		return null;
	}
	public static void main(String args[]){
		int nG,nV,nE;
		int i,j,k,p,q,r;
		int id1,id2,nMI;
		int mindegree, target;
		boolean DEBUG=false;
		Node V[],Vans[];
		Node vmin,vtmp;
		Vector Vrems = new Vector();
		Scanner stdin = new Scanner(new BufferedInputStream(System.in));
		nG = stdin.nextInt();
		for(i=0;i<nG;i++){
			nV = stdin.nextInt();
			nE = stdin.nextInt();
			V = new Node[nV];
			for(j=0;j<nV;j++){
				V[j] = new Node(j+1);
			}
			for(j=0;j<nE;j++){
				id1 = stdin.nextInt();
				id2 = stdin.nextInt();
				if (id1 != id2){
					V[id1-1].addNeighbor(id2);
					V[id2-1].addNeighbor(id1);
				}
			}
			if(DEBUG){
				for(j=0;j<nV;j++){
					System.out.println("Node "+V[j].id+" has "+V[j].getDegree()+" neighbors");
				}
			}
			Vans = findMI(V);

			/*Find Max. Ind. Set*/
			nMI=0;
			StringBuffer sb = new StringBuffer();
			for(j=0;j<nV;j++){
				if(V[j].color == Node.BLACK){
					nMI++;
					sb.append(V[j].id+" ");
				}
			}
			System.out.println(""+nMI);
			System.out.println(sb.toString());
		}
	}
	
}

class Node{
	final static int BLACK=0;
	final static int WHITE=1;
	final static int UNDEF=-1; 
	public int color;
	public int id;
	public Vector neighbor;
	public Node(int nid){
		id = nid;
		color = UNDEF;
		neighbor = new Vector(); 
	}
	public void addNeighbor(int nn){
		neighbor.add(""+nn);
	}
	public void addNeighbor(String s){
		neighbor.add(s);
	}
	public void removeNeighbor(int nn){
		neighbor.remove(""+nn);
	}
	
	public int getDegree(){
		return neighbor.size();
	}
	public Node clone(){
		Node newNode;
		int i,tmp;
		newNode = new Node(0);
		newNode.id = this.id;
		newNode.color = this.color;
		
		for(i=0;i<neighbor.size();i++){
			tmp = Integer.parseInt(""+neighbor.elementAt(i));
			newNode.addNeighbor(tmp);
		}
		return newNode;
	}
}