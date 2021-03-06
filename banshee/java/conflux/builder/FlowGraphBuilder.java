/*
 * Copyright (c) 2000-2004
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */
package conflux.builder;

import soot.*;
import soot.util.queue.*;
import java.util.*;
import conflux.flowgraph.*;

/** Builds a context-sensitive type-based flow graph
 *
 * @author John Kodumal
 */
public class FlowGraphBuilder {
    FlowGraph fg;


    public FlowGraphBuilder() {
    }

    /** Jimplify all methods; useful for separating Jimplification
     * time from analysis time
     */
    // TODO -- this should look just like the soot version
    public void preJimplify() {
    }

    public FlowGraph setup(Map options) {
	fg = new FlowGraph();

	return fg;
    }

    /** Fills in the flow graph */
    public void build() {
	//	QueueReader callEdges = ofcg.callGraph().listener();
	// ofcg.build();
	// reachables = ofcg.reachableMethods();
	// reachables.update();

        for( Iterator cIt = Scene.v().getClasses().iterator(); cIt.hasNext(); ) {
            final SootClass c = (SootClass) cIt.next();
	    handleClass( c );
	}
        Stmt s = null;
        while(callEdges.hasNext()) {
            Edge e = (Edge) callEdges.next();
            //MethodFlowGraph.v( fg, e.tgt() ).addToFlowGraph(null);

            //fg.addCallTarget( e );
        }


    }

}