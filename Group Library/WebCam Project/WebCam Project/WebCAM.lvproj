<?xml version='1.0'?>
<Project Type="Project" LVVersion="8508002">
   <Item Name="My Computer" Type="My Computer">
      <Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="server.tcp.enabled" Type="Bool">false</Property>
      <Property Name="server.tcp.port" Type="Int">0</Property>
      <Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
      <Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
      <Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
      <Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="specify.custom.address" Type="Bool">false</Property>
      <Item Name="TypeDefs" Type="Folder">
         <Item Name="States.ctl" Type="VI" URL="States.ctl"/>
         <Item Name="State_Variables.ctl" Type="VI" URL="State_Variables.ctl"/>
      </Item>
      <Item Name="SubVIs" Type="Folder">
         <Item Name="WebCAM_Init.vi" Type="VI" URL="WebCAM_Init.vi"/>
      </Item>
      <Item Name="Webcam.vi" Type="VI" URL="Webcam.vi"/>
      <Item Name="Dependencies" Type="Dependencies">
         <Item Name="avicap32.dll" Type="Document" URL="../../../WINDOWS/system32/avicap32.dll"/>
         <Item Name="user32.dll" Type="Document" URL="../../../WINDOWS/system32/user32.dll"/>
         <Item Name="System.Windows.Forms" Type="Document" URL="System.Windows.Forms"/>
      </Item>
      <Item Name="Build Specifications" Type="Build"/>
   </Item>
</Project>
