module Phy802154
{
    gates:
        output pdSapOut;
        input pdSapIn;

        output plmeSapOut;
        input plmeSapIn;

        output rfSapOut;
        input rfSapIn;
        
        input rfControlIn;
    submodules:
        pd: Pd;
        plme: Plme;
        phyPib: PhyPib;
    connections:
		// external connections
		pdSapIn --> pd.pdSapIn;
		pdSapOut <-- pd.pdSapOut;
		
		plmeSapIn --> plme.plmeSapIn;
		plmeSapOut <-- plme.plmeSapOut;
		
		rfSapIn --> pd.rfSapIn;
		rfSapOut <-- pd.rfSapOut;
		
		//rfCtrlIn --> plme.rfCtrlSapIn;
		//rfCtrlOut <-- plme.rfCtrlSapOut;
		
		// internal connections
		pd.plmeOut --> plme.pdIn;
		pd.plmeIn <-- plme.pdOut;
		
		plme.phyPibOut --> phyPib.plmeIn;
		plme.phyPibIn <-- phyPib.plmeOut;
		
		rfControlIn --> pd.rfControlIn;
}
