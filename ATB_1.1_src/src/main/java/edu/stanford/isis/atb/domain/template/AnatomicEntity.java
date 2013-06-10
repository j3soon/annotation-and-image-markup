/*
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/



package edu.stanford.isis.atb.domain.template;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

import javax.validation.Valid;

import org.simpleframework.xml.Attribute;
import org.simpleframework.xml.ElementList;
import org.simpleframework.xml.Root;
import org.simpleframework.xml.core.Commit;

import edu.stanford.isis.atb.domain.template.NumberedElement.NumberingCommand;

/**
 * @author Vitaliy Semeshko
 */

@Root(name="AnatomicEntity", strict=false)
public class AnatomicEntity extends AbstractRemovableElement {

	@Attribute(required=false)
	private boolean annotatorConfidence;

	@Valid
	@ElementList(name="AnatomicEntityCharacteristic", inline=true, required=false)
	private List<AnatomicEntityCharacteristic> characteristics;
	
	@SuppressWarnings("unused")
	@Commit
	private void afterPropertiesSet() {
		if (characteristics != null) {
			for (AnatomicEntityCharacteristic characteristic : characteristics) {
				characteristic.initRemoveCommand(characteristics);
				characteristic.initContext(characteristics);
				characteristic.setNumberingCommand(new NumberingCommand() {
					@Override
					public void execute() {
						reNumberCharacteristics();
					}
				});
			}
		}
	}
	
	public boolean isAnnotatorConfidence() {
		return annotatorConfidence;
	}

	public void setAnnotatorConfidence(boolean annotatorConfidence) {
		this.annotatorConfidence = annotatorConfidence;
	}

	public Collection<AnatomicEntityCharacteristic> getCharacteristics() {
		if (characteristics == null) {
			return Collections.emptyList();
		}
		return characteristics;
	}

	public void addCharacteristic(AnatomicEntityCharacteristic characteristic) {
		if (characteristics == null) {
			characteristics = new ArrayList<AnatomicEntityCharacteristic>();
		}
		characteristics.add(characteristic);
		characteristic.setItemNumber(characteristics.size());
		characteristic.initRemoveCommand(characteristics);
		characteristic.initContext(characteristics);
		characteristic.setNumberingCommand(new NumberingCommand() {
			@Override
			public void execute() {
				reNumberCharacteristics();
			}
		});
	}

	private void reNumberCharacteristics() {
		// update item numbers
		for (int i = 0; i < characteristics.size(); i++) {
			AnatomicEntityCharacteristic c = characteristics.get(i);
			c.setItemNumber(i+1);
		}
	}
	
	@Override
	public String toString() {
		return "Anatomic Entity";
	}
	
}